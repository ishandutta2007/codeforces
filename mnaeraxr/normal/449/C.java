import java.io.*;
import java.util.*;

public class Main {
    InputReader in;
    PrintWriter out;
    
    public int gcd(int a, int b){
        while (b != 0){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        
        int[] prime = new int[n + 1];
        
        for (int i = 2; i <= n; ++i){
            if (prime[i] != 0) continue;
            for (int j = 2 * i; j <= n; j += i)
                prime[j] = prime[j] == 0 ? i : prime[j];
        }       
        
        int answer = 0, other = -1;
        TreeMap<Integer, Integer> couples = new TreeMap<Integer, Integer>();
        
        for (int i = 2; i <= n; ++i){
            if (prime[i] == 0) continue;
            
            if (i % 2 == 0 && prime[i / 2] == 0){
                couples.put(i, i / 2);
                couples.put(i / 2, i);
                answer++;
            }
            else{
                if (other == -1){
                    other = i;
                }
                else{
                    int a = other, b = i;
                    
                    other = -1;
                    answer++;
                    
                    if (gcd(a, b) > 1){
                        couples.put(a, b);
                        couples.put(b, a);
                    }   
                    else{
                        int f = prime[a] * prime[b];
                        int p = couples.get(f);
                        
                        if (gcd(a, p) > 1){
                            couples.put(a, p);
                            couples.put(p, a);
                            couples.put(b, f);
                            couples.put(f, b);
                        }
                        else{
                            couples.put(a, f);
                            couples.put(f, a);
                            couples.put(b, p);
                            couples.put(p, b);
                        }
                    }
                }
            }
        }
        
        out.println(answer);
        Set<Integer> K = couples.keySet();
        
        Iterator<Integer> it = K.iterator();
        
        while (it.hasNext()){
            Integer k = it.next();
            Integer v = couples.get(k);
            
            if (k < v){
                out.print(k);
                out.print(" ");
                out.println(v);
            }
        }
    }

    public void run() {
        try {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class InputReader {
        BufferedReader br;
        StringTokenizer st;

        InputReader(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public InputReader(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}