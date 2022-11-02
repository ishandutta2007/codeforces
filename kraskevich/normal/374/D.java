import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        reader = new BufferedReader(new InputStreamReader(input));
        printer = new PrintWriter(output);

        int n = getNextInt();
        int m = getNextInt();
        int last = 0;
        int[] values = new int[n];
        int[] a = new int[m];
        SegmentTree tree = new SegmentTree(n);
        for (int counter = 0; counter < m; counter++)
            a[counter] = getNextInt();
        for (int counter = 0; counter < n; counter++) {
            int type = getNextInt();
            if (type == 0 || type == 1) {
                values[last] = type;
                tree.addAtPos(last);
                last++;
            }
            else {
                for (int step = 0; step < m; step++) {
                    int curr = a[step] - step - 1;
                    if (curr >= tree.getSum(0, n - 1))
                        break;
                    tree.erase(curr);
                }
            }
        }
        if (tree.getSum(0, n - 1) == 0) {
            printer.println("Poor stack!");
        }
        else {
            for (int counter = 0; counter < last; counter++) {
                if (tree.getSum(counter, counter) > 0)
                    printer.print(values[counter]);
            }
        }
        printer.close();
    }

    static BufferedReader reader;
    static StringTokenizer st;
    static PrintWriter printer;

    static String getNextToken() throws IOException {
        if (st == null || !st.hasMoreTokens()) {
            String newLine = reader.readLine();
            if (newLine == null)
                return null;
            st = new StringTokenizer(newLine);
        }
        return st.nextToken();
    }

    static int getNextInt() throws IOException {
        return Integer.parseInt(getNextToken());
    }
}

class SegmentTree {
    private int[] tree;
    private int left;
    private int right;

    public SegmentTree() {}

    public SegmentTree(int size) {
        tree = new int[4 * size];
        left = 0;
        right = size - 1;
    }

    public int getSum(int left, int right) {
        return getSum(0, this.left, this.right, left, right);
    }

    public void addAtPos(int pos) {
        addAtPos(0, left, right, pos);
    }

    public void erase(int pos) {
        erase(0, left, right, pos);
    }

    private int getSum(int index, int nodeLeft, int nodeRight, int left, int right) {
        if (left == nodeLeft && right == nodeRight)
            return tree[index];
        int middle = (nodeLeft + nodeRight) / 2;
        int sumLeft = 0;
        int sumRight = 0;
        if (left <= middle)
            sumLeft = getSum(index * 2 + 1, nodeLeft, middle, left, Math.min(right, middle));
        if (right > middle)
            sumRight = getSum(index * 2 + 2, middle + 1, nodeRight, Math.max(left, middle + 1), right);
        return sumLeft + sumRight;
    }

    private void addAtPos(int index, int left, int right, int pos) {
        tree[index]++;
        if (left == right)
            return;
        int middle = (left + right) / 2;
        if (pos <= middle)
            addAtPos(index * 2 + 1, left, middle, pos);
        else
            addAtPos(index * 2 + 2, middle + 1, right, pos);
    }

    private void erase(int index, int left, int right, int pos) {
        tree[index]--;
        if (left == right)
            return;
        int middle = (left + right) / 2;
        int sumLeft = tree[index * 2 + 1];
        if (sumLeft > pos)
            erase(index * 2 + 1, left, middle, pos);
        else
            erase(index * 2 + 2, middle + 1, right, pos - sumLeft);
    }
}