import kotlin.math.*

class Block(val l:Int,val r:Int,val id:Int) {
    var y=-1
}

class STNode(val l:Int,val r:Int) {
    val m=l+(r-l)/2;
    val lft: STNode? = if(l==r) null else STNode(l,m);
    val rgt: STNode? = if(l==r) null else STNode(m+1,r);
    var leftHighest: Block? = null
    var rightHighest: Block? = null
    var lst = mutableListOf<Block>()
    
    private fun bestLeft(a: Block?, b: Block?) = if(a!=null&&(b==null||a.y>b.y||a.y==b.y&&a.l<b.l)) a else b
    private fun bestRight(a: Block?, b: Block?) = if(a!=null&&(b==null||a.y>b.y||a.y==b.y&&a.r>b.r)) a else b
    private fun update() { 
        leftHighest=if(lst.isEmpty()) null else lst.last()
        if(lft!=null) leftHighest=bestLeft(leftHighest,lft.leftHighest)
        if(rgt!=null) leftHighest=bestLeft(leftHighest,rgt.leftHighest)
        rightHighest=if(lst.isEmpty()) null else lst.last()
        if(lft!=null) rightHighest=bestRight(rightHighest,lft.rightHighest)
        if(rgt!=null) rightHighest=bestRight(rightHighest,rgt.rightHighest)
    }

    fun getLeftHighest(L:Int,R:Int):Block? {
        if(L<=l&&r<=R) return leftHighest;
        var ret:Block? = if(lst.isEmpty()) null else lst.last();
        if(L<=m) ret=bestLeft(ret,lft!!.getLeftHighest(L,R))
        if(m+1<=R) ret=bestLeft(ret,rgt!!.getLeftHighest(L,R))
        return ret;
    }
    fun getRightHighest(L:Int,R:Int):Block? {
        if(L<=l&&r<=R) return rightHighest;
        var ret:Block? = if(lst.isEmpty()) null else lst.last();
        if(L<=m) ret=bestRight(ret,lft!!.getRightHighest(L,R))
        if(m+1<=R) ret=bestRight(ret,rgt!!.getRightHighest(L,R))
        return ret;
    }
    fun addBlock(b: Block) {
        if(b.l<=l&&r<=b.r) {
            if(!lst.isEmpty()) assert(b.y>lst.last().y)
            lst.add(b)
        } else {
            if(b.l<=m) lft!!.addBlock(b)
            if(m+1<=b.r) rgt!!.addBlock(b)
        }
        update()
    }
    fun removeBlock(b: Block) {
        if(b.l<=l&&r<=b.r) {
            assert(!lst.isEmpty()&&lst.last()==b)
            lst.removeAt(lst.lastIndex)
        } else {
            if(b.l<=m) lft!!.removeBlock(b)
            if(m+1<=b.r) rgt!!.removeBlock(b)
        }
        update()
    }
}

fun main() {
    val (n,maxx)=readLine()!!.split(" ").map{it.toInt()}
    val blocks = List<Block>(n) { val (l,r)=readLine()!!.split(" ").map{it.toInt()-1}; Block(l,r,it);  }
    
    val stroot = STNode(0,maxx-1)
    var cnt=0
    for(b in blocks) {
        while(true) {
            val leftTop=stroot.getLeftHighest(b.l,b.r)
            if(leftTop==null) break
            val rightTop=stroot.getRightHighest(b.l,b.r)
            assert(rightTop!=null)
            if(rightTop==null) break
            //println("while adding ${b.l+1}..${b.r+1}, fall on ${leftTop.l+1}..${leftTop.r+1} and ${rightTop.l+1}..${rightTop.r+1}")
            if(leftTop.l<b.l||rightTop.r>b.r) break
            stroot.removeBlock(leftTop)
            --cnt
        }
        val top=stroot.getLeftHighest(b.l,b.r)
        b.y=if(top!=null) top.y+1; else 0
        //println("for ${b.l+1}..${b.r+1}, y=${b.y}")
        stroot.addBlock(b)
        ++cnt
        println(cnt)
    }
}