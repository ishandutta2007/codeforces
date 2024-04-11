import java.util.*

fun gcd(a:Long,b:Long):Long{
    if(b==0.toLong())return a;
    return gcd(b,a%b);
}

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);

    var S=cin.next();
    
    var a:Long=0;
    var b:Long=0;
    var aa:Long=0;
    var bb:Long=0;
    var cur=2;
    while(S[cur]!='('){
        a=a*10+S[cur].toInt()-'0'.toInt();
        cur++;
        aa++;
    }
    cur++;
    while(S[cur]!=')'){
        b=b*10+S[cur].toInt()-'0'.toInt();
        cur++;
        bb++;
    }
    
    
    var x:Long=a;
    var y:Long=1;
    for(i in 1..aa)y*=10;
    var g:Long=gcd(x,y);
    x/=g;y/=g;
    
    if(b==0.toLong()){
        println("${x}/${y}");
        return;
    }
    
    var z:Long=b;
    var w:Long=0;
    for(i in 1..bb)w=w*10+9;
    for(i in 1..aa)w*=10;
    g=gcd(z,w);
    z/=g;w/=g;
    a=x*w+y*z;
    b=y*w;
    g=gcd(a,b);
    a/=g;b/=g;
    println("${a}/${b}");
}