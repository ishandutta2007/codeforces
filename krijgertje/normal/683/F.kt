fun main(args: Array<String>) {
	val s=readLine()!!
	val sb=StringBuilder()
	var instr=false
	var insent=false
	var inword=false
	for(i in 0..s.length-1) {
		if(s[i]==' ') {
			inword=false
		} else if(s[i]==',') {
			sb.append(s[i])
			inword=false
		} else if(s[i]=='.') {
			sb.append(s[i])
			inword=false; insent=false
		} else {
			if(!inword&&instr) sb.append(' ')
			sb.append(if (!insent) s[i].toUpperCase() else s[i].toLowerCase())
			instr=true; insent=true; inword=true
		}
	}
	println(sb)
}