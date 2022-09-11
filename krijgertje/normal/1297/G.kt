import kotlin.math.*

class Opt(val len: Int,val ways: Long) {}
var precalc=arrayOf<MutableList<Opt>>()

fun choose(n: Int, k: Int):Long {
    var ret=1L
    for(i in 0 until k) ret=ret*(n-i)/(i+1)
    return ret
}

fun calc(len: Int, two: Int, three: Int, five: Int, seven: Int):Long {
    var ret=0L
    val maxsix=min(two,three)
    for(six in 0..maxsix) {
        val maxnine=(three-six)/2
        for(nine in 0..maxnine) {
            val realthree=three-six-2*nine
            var remlen=len
            var wayssofar=1L
            if(realthree>remlen) continue; wayssofar*=choose(remlen,realthree); remlen-=realthree;
            if(five>remlen) continue; wayssofar*=choose(remlen,five); remlen-=five;
            if(six>remlen) continue; wayssofar*=choose(remlen,six); remlen-=six;
            if(seven>remlen) continue; wayssofar*=choose(remlen,seven); remlen-=seven;
            if(nine>remlen) continue; wayssofar*=choose(remlen,nine); remlen-=nine;
            for(opt in precalc[two-six]) {
                if(opt.len>remlen) continue;
                ret+=wayssofar*choose(remlen,opt.len)*opt.ways;
            }
        }
    }
    //println("calc($len -> $two,$three,$five,$seven)=$ret")
    return ret
}

fun main() {
    val (product,position)=readLine()!!.split(" ").map{it.toInt()}
    var remproduct=product
    var two=0; while(remproduct%2==0) { remproduct/=2; ++two }
    var three=0; while(remproduct%3==0) { remproduct/=3; ++three }
    var five=0; while(remproduct%5==0) { remproduct/=5; ++five }
    var seven=0; while(remproduct%7==0) { remproduct/=7; ++seven }
    if(remproduct!=1) { println(-1); return }
    //println("$two $three $five $seven")
    precalc=Array(two+1){mutableListOf<Opt>()}
    for(i in 0..two) {
        val maxeight=i/3
        for(eight in 0..maxeight) {
            val maxfour=(i-3*eight)/2
            for(four in 0..maxfour) {
                var realtwo=i-3*eight-2*four
                val len=realtwo+four+eight
                var ways=choose(len,realtwo)*choose(len-realtwo,four)
                precalc[i].add(Opt(len,ways))
                //println("$i: len=$len ways=$ways")
            }
        }
    }
    var rembefore=position-1L
    var len=1
    while(true) {
        val cnt=calc(len,two,three,five,seven)
        if(rembefore<cnt) break
        rembefore-=cnt; ++len
    }
    //println("len=$len")
    val ret=CharArray(len)
    for(i in 0 until len) {
        var done=false
        if(!done) { val cnt=calc(len-i-1,two,three,five,seven); if(rembefore<cnt) { ret[i]='1'; done=true; } else rembefore-=cnt; }
        if(!done&&two>=1) { val cnt=calc(len-i-1,two-1,three,five,seven); if(rembefore<cnt) { ret[i]='2'; --two; done=true; } else rembefore-=cnt; }
        if(!done&&three>=1) { val cnt=calc(len-i-1,two,three-1,five,seven); if(rembefore<cnt) { ret[i]='3'; --three; done=true; } else rembefore-=cnt; }
        if(!done&&two>=2) { val cnt=calc(len-i-1,two-2,three,five,seven); if(rembefore<cnt) { ret[i]='4'; two-=2; done=true; } else rembefore-=cnt; }
        if(!done&&five>=1) { val cnt=calc(len-i-1,two,three,five-1,seven); if(rembefore<cnt) { ret[i]='5'; --five; done=true; } else rembefore-=cnt; }
        if(!done&&two>=1&&three>=1) { val cnt=calc(len-i-1,two-1,three-1,five,seven); if(rembefore<cnt) { ret[i]='6'; --two; --three; done=true; } else rembefore-=cnt; }
        if(!done&&seven>=1) { val cnt=calc(len-i-1,two,three,five,seven-1); if(rembefore<cnt) { ret[i]='7'; --seven; done=true; } else rembefore-=cnt; }
        if(!done&&two>=3) { val cnt=calc(len-i-1,two-3,three,five,seven); if(rembefore<cnt) { ret[i]='8'; two-=3; done=true; } else rembefore-=cnt; }
        if(!done&&three>=2) { val cnt=calc(len-i-1,two,three-2,five,seven); if(rembefore<cnt) { ret[i]='9'; three-=2; done=true; } else rembefore-=cnt; }
        assert(done)
    }
    assert(rembefore==0L)
    println(String(ret))
}