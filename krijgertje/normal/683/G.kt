fun gcd(a:Int, b:Int):Int = if (b==0) a else gcd(b,a%b)

fun main(args: Array<String>) {
	val s=readLine()!!
	var part=0;	var p=0; var q=0; var bpw=1; var cpw=1;
	for(i in 0..s.length-1) {
		if(s[i]=='.') { part=1; continue; }
		if(s[i]=='(') { part=2; continue; }
		if(s[i]==')') { part=3; continue; }
		val d=s[i].toInt()-'0'.toInt()
		if(part<=2) p=p*10+d
		if(part<=1) q=q*10+d
		if(part==1) bpw*=10 else if(part==2) cpw*=10
	}
	val num=p-q; val den=bpw*cpw-bpw; val g=gcd(num,den)
	print(num/g); print("/"); print(den/g); println()
}

// x=aaa.bbbb(cc) -> x = (aaabbbbcc-aaabbbb)/(10^(blen+clen)-10^blen)