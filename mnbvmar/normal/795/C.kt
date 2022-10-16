fun main(arg: Array<String>) {
  var a = readLine()!!.split(" ").map(String::toInt)[0]
  if (a % 2 == 1) {
    print(7)
    a -= 3
  }
  while (a >= 2) {
    print(1)
    a -= 2
  }
  println("")
}