fun main(args: Array<String>) {
    var (n) = readLine()!!.split(' ').map(String::toInt);
    if(n%2==1) { print('7'); n-=3; }
    while(n>0) { print('1'); n-=2; }
    println();
}