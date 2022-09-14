import java.util.Scanner;
public class Main {int nf,ni,w;String[] g=new String[10];void run(){
Scanner in=new Scanner(System.in);
nf=in.nextInt();ni=in.nextInt();w=in.nextInt();
for(int i=0;i<nf;++i)g[i]=in.next();
int ret=0;for(int j=0;j<ni;++j){int c=0;for(int i=0;i<nf;++i)if(g[i].charAt(j)=='Y')++c;if(c>=w) ++ret;}System.out.println(ret);
}public static void main(String[]a){new Main().run();}}//kitten