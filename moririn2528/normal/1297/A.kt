fun main(){
    var n=readLine()!!.toInt();
    for(i in 1 .. n){
        var a=readLine()!!.toInt()
        if(a>=1000000){
            var b=a/1000000;
            a%=1000000;
            if(a>=500000)b++;
            print(b);print("M");
        }else if(a>=1000){
            var b=a/1000;
            a%=1000;
            if(a>=500)b++;
            if(b==1000){
                print("1M");
            }else{
                print(b);print("K");
            }
        }else print(a);
        print("\n");
    }
}