class Person(val name:String, val h:Int) : Comparable<Person> {
	override operator fun compareTo(other: Person):Int = this.h-other.h
}

fun main(args: Array<String>) {
	val n=readLine()!!.toInt()
	val persons = mutableListOf<Person>()
	for(i in 0..n-1) { val s=readLine()!!.split(' '); persons.add(Person(s[0],s[1].toInt())); }
	for(person in persons.sorted()) println(person.name)
}