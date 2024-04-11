fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        if (s.all { it == '=' }) return@repeat println('=')
        if (s.all { it == '<' || it == '=' }) return@repeat println('<')
        if (s.all { it == '>' || it == '=' }) return@repeat println('>')
        println('?')
    }
}