fun main(){
    repeat(readLine()!!.toInt()){
        val s = readLine()!!.toCharArray()
        for (i in 0 until s.size step 2) s[i] = if (s[i] == 'a') 'b' else 'a'
        for (i in 1 until s.size step 2) s[i] = if (s[i] == 'z') 'y' else 'z'
        println(s.joinToString(""))
    }
}