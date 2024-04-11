fun main() {
    var t = readLine()!!.toInt()
    while (t > 0)
    {
        t--
       	val arr = readLine()!!
       	var eq = 0
       	var lo = 0
       	var hi = 0
       	for(i in arr)
       	{
       	    when(i)
       	    {
       	        '=' -> eq++
       	        '<' -> lo++
       	        '>' -> hi++
       	    }
       	}
        if ( lo > 0 && hi > 0 )
            println('?')
        else if (lo == 0 && hi == 0)
            println('=')
        else if (lo > 0)
            println('<')
        else
            println('>')
    }
}