import java.io.*;
import java.util.*;

public class laptop
{
    private static Reader in;
    private static PrintWriter out;

    public static void main (String [] args) throws IOException {
        in = new Reader ();
        out = new PrintWriter (System.out, true);
        
        int N = in.nextInt();
        Laptop [] laptops = new Laptop [N];
        for (int i = 0; i < N; i++)
            laptops [i] = new Laptop (in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), i + 1);
        Arrays.sort (laptops);
            
        boolean [] canuse = new boolean [N];
        Arrays.fill (canuse, true);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++)
                if (laptops [j].better (laptops [i]))
                    canuse [i] = false;
        }
        
        int minprice = Integer.MAX_VALUE, index = -1;
        for (int i = 0; i < N; i++)
            if (canuse [i]) {
                if (laptops [i].price < minprice) {
                    minprice = laptops [i].price;
                    index = laptops [i].idx;
                }
            }
            
        out.println (index);
    }
    
    static class Laptop implements Comparable <Laptop> {
        public int price, a, b, c, idx;
        public Laptop (int a, int b, int c, int price, int idx) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.price = price;
            this.idx = idx;
        }
        
        public boolean better (Laptop other) {
            return a > other.a && b > other.b && c > other.c;
        }
        
        public int compareTo (Laptop other) {
            return a - other.a;
        }
    }
}

/** Faster input **/
class Reader {
    final private int BUFFER_SIZE = 1 << 16;private DataInputStream din;private byte[] buffer;private int bufferPointer, bytesRead;
    public Reader(){din=new DataInputStream(System.in);buffer=new byte[BUFFER_SIZE];bufferPointer=bytesRead=0;}
    public Reader(String file_name)throws IOException{din=new DataInputStream(new FileInputStream(file_name));buffer=new byte[BUFFER_SIZE];bufferPointer=bytesRead=0;}
    public String readLine()throws IOException{byte[] buf=new byte[1024];int cnt=0,c;
        while((c=read())!=-1){if(c=='\n')break;buf[cnt++]=(byte)c;}return new String(buf,0,cnt);}
    public int nextInt()throws IOException{int ret=0;byte c=read();while(c<=' ')c=read();boolean neg=(c=='-');
        if(neg)c=read();do{ret=ret*10+c-'0';}while((c=read())>='0'&&c<='9');if(neg)return -ret;return ret;} 
    public long nextLong()throws IOException{long ret=0;byte c=read();while(c<=' ')c=read();boolean neg=(c=='-');
        if(neg)c=read();do{ret=ret*10+c-'0';}while((c=read())>='0'&&c<='9');if(neg)return -ret;return ret;}
    public double nextDouble()throws IOException{double ret=0,div=1;byte c=read();while(c<=' ')c=read();boolean neg=(c=='-');if(neg)c = read();do {ret=ret*10+c-'0';}while((c=read())>='0'&&c<='9');
        if(c=='.')while((c=read())>='0'&&c<='9')ret+=(c-'0')/(div*=10);if(neg)return -ret;return ret;}
    private void fillBuffer()throws IOException{bytesRead=din.read(buffer,bufferPointer=0,BUFFER_SIZE);if(bytesRead==-1)buffer[0]=-1;}
    private byte read()throws IOException{if(bufferPointer==bytesRead)fillBuffer();return buffer[bufferPointer++];}
    public void close()throws IOException{if(din==null) return;din.close();}
}