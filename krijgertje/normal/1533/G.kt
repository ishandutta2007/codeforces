fun run() {
    val (h,w) = readLine()!!.split(" ").map{it.toInt()}
    val g = (0 until h).map{readLine()!!.split(" ").map{it.toInt()}}
    
    val done = Array(h) {Array(w) {false} }
    val seq = mutableListOf<Int>()
    
    fun dfs(x:Int,y:Int) {
        done[x][y] = true
        seq.add(g[x][y])
        for(dx in -1..+1) for(dy in -1..+1) if(Math.abs(dx)+Math.abs(dy)==1) {
            val (nx,ny) = listOf(x+dx,y+dy)
            if(nx !in 0 until h || ny !in 0 until w || g[nx][ny]==0 || done[nx][ny]) continue
            dfs(nx,ny)
            seq.add(g[x][y])
        }
    }
    val sx = (0 until h).first{x->(0 until w).any{y->g[x][y]!=0}}
    val sy = (0 until w).first{y->g[sx][y]!=0}
    dfs(sx,sy)
    val cnt = (0 until h).map{x->(0 until w).filter{y->g[x][y]!=0}.count()}.sum()
    if(seq.size!=2*cnt-1) { println("-1"); return }
    println("$cnt $cnt")
    (0 until cnt).map{i->println(seq.subList(i,i+cnt).joinToString(" "))}
}

fun main() {
    val ncase = readLine()!!.toInt()
    repeat(ncase) { run() }
}