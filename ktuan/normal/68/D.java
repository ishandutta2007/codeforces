import java.util.*;
import java.math.*;
import java.io.*;

public class BaiD {
    
    class Node {
        Node left, right;
        int val, sum;
    }
    
    void add(Node root, int node, int val) {
        int x = node;
        ArrayList<Integer> ar = new ArrayList<Integer>();
        while(x > 0) {
            ar.add(x);
            x /= 2;
        }
        Node p = root;
        for(int i=ar.size()-1;i>=0;--i) {
            p.sum += val;
            if(i > 0) {
                int oldNum = ar.get(i);
                int newNum = ar.get(i-1);
                if(oldNum * 2 == newNum) {
                    if(p.left == null) {
                        p.left = new Node();
                    }
                    p = p.left;
                }
                else {
                    if(p.right == null) {
                        p.right = new Node();
                    }
                    p = p.right;
                }
            }
        }
        p.val += val;
    }
    
    double calc(Node root, int h, int cur, int maxi) {
        cur += root == null ? 0 : root.val;
        if(h == 0) return Math.max(cur, maxi);
        int le = (root != null && root.left != null) ? root.left.sum : 0;
        int ri = (root != null && root.right != null) ? root.right.sum : 0;
        if(le <= ri)
            return 0.5 * (Math.max(cur + ri, maxi) + calc(root == null ? null : root.right, h - 1, 0, Math.max(maxi, cur + le)));
        else
            return 0.5 * (Math.max(cur + le, maxi) + calc(root == null ? null : root.left, h - 1, 0, Math.max(maxi, cur + ri)));
    }
    
    public void run() throws Exception {
        BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(kb.readLine());
        int h = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        Node root = new Node();
        for(int i=0;i<q;++i) {
            st = new StringTokenizer(kb.readLine());
            String command = st.nextToken();
            if(command.equals("add")) {
                int node = Integer.parseInt(st.nextToken());
                int val = Integer.parseInt(st.nextToken());
                add( root, node, val);
            }
            else {
                double res = calc( root, h, 0, 0);
                System.out.printf("%.6f\n", res);
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        new BaiD().run();
    }
}