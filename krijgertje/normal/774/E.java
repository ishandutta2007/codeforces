import java.util.*;

public class Sol{
	public static void main(String[] argc){
		Scanner sc=new Scanner(System.in);
		String ss=sc.next();
		int MOD=sc.nextInt();
		char[] s=ss.toCharArray();
		int len=s.length;
		int cur=0;
		for(int i=0;i<len;++i) cur=(int)(((long)cur*10+(s[i]-'0'))%MOD);
		int ret=cur;
		int p=1; for(int i=0;i<len;++i) p=(int)((long)p*10%MOD);
		for(int i=0;i<len-1;++i) {
		    cur=(int)(((long)10*cur+(long)(1+MOD-p)*(s[i]-'0'))%MOD);
		    if(s[i+1]!='0'&&cur<ret) ret=cur;
		}
		System.out.println(ret);
	}
}