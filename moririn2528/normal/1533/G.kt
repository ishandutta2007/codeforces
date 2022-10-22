//val n = readLine()!!.toInt();
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun dfs(x:Int, y:Int, grid:Array<IntArray>, used:Array<IntArray>, vs:MutableList<Int>): Int{
    if(x<0 || y<0 || grid.size<=x || grid[0].size<=y)return 0;
    if(used[x][y]>0 || grid[x][y]==0)return 0;
    used[x][y]=1;
    vs.add(grid[x][y]);
    var a=0;
    for(i in -1..1){
        for(j in -1..1){
            if((i+j+2)%2==0)continue;
            val b=dfs(x+i,y+j,grid,used,vs);
            a+=b;
            if(b>0)vs.add(grid[x][y]);
        }
    }
    return a+1;
}

fun solve() {
    val (n,m)=readLine()!!.split(" ").map{it.toInt()}.toMutableList();
    var grid=Array(n){IntArray(m)};
    var used=Array(n){IntArray(m)};
    var x=0;
    var y=0;
    var cnt=0;
    for(i in 0 until n) {
        val list = readLine()!!.split(" ").map { it.toInt() }.toMutableList();
        for (j in 0 until m) {
            grid[i][j] = list[j];
            if (grid[i][j] != 0) {
                x = i;
                y = j;
                cnt++;
            }
        }
    }
    var vs:MutableList<Int> = mutableListOf();
    var cnt2=dfs(x,y,grid,used,vs);
    if(cnt!=cnt2){
        println(-1);
        return;
    }
    x=min(cnt,vs.size);
    y=vs.size-x+1;
    println("$x $y")
    for(i in 0 until x) {
        val list:MutableList<Int> = mutableListOf();
        for (j in 0 until y) {
            list.add(vs[i + j]);
        }
        println(list.joinToString(separator = " "));
    }
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 1..n){
        solve();
    }
}