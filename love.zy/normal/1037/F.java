import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        int n,k;
        int Array_[] = new int[3000001],stack[] = new int[2000001],top,lptr[] = new int[2000001],rptr[] = new int[2000001];
        final int INF = 0x3f3f3f3f;
        final long mod = (long)1e9 + 7;
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt(); k = in.nextInt();
            for (int i = 1; i <= n; ++i) Array_[i] = in.nextInt();
            Array_[0]=Array_[n+1]=INF;
            top = 1;
            for (int i = 1; i <= n + 1; ++i){
                while(top != 0&&Array_[stack[top]]<Array_[i]) rptr[stack[top--]]=i-1;
                lptr[i]=stack[top]+1;
                stack[++top]=i;
            }
            long result = 0;
            for (int i = 1; i <= n; ++i){
                int len=rptr[i]-lptr[i]+1;
                int temp_m=Math.min(i-lptr[i],rptr[i]-i)/(k-1);
                long temp_s = 0;
                if(temp_m != 0){
                    temp_s=(temp_s + (temp_m + ((long)(temp_m+1)*temp_m/2) %mod * (k-1)%mod ) %mod) %mod;
                }
                int nwa=Math.max(i-lptr[i],rptr[i]-i)/(k-1);
                if(nwa>temp_m){
                    int Len=Math.min(i-lptr[i],rptr[i]-i)+1;
                    temp_s=(temp_s + (long)( nwa-temp_m )*Len%mod)%mod;
                }
                int ort=(len-1)/(k-1);
                if(ort>nwa)
                {
                    temp_s=(temp_s + (long)(ort-nwa)*len%mod - ((long)(k-1)*((long)(ort-nwa)*(ort+nwa+1)/2%mod)%mod+mod)%mod)%mod;
                }
                result=(result+(long)Array_[i]*temp_s%mod)%mod;

            }
            out.println(result);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}