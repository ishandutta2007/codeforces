object Solution {
  var tokens: List[String] = null;

  def nextToken(): String = {
    if (tokens.isEmpty) {
      throw new Exception("nope")
    }
    val token = tokens.head
    tokens = tokens.tail
    token
  }

  def parse(buf: StringBuffer) {
    if (nextToken() == "int") {
      buf.append("int")
    } else {
      buf.append("pair<")
      parse(buf)
      buf.append(",")
      parse(buf)
      buf.append(">")
    }
  }

  def main(args: Array[String]) {
    val n = readInt()
    tokens = readLine().split(" ").toList
    try {
      val buf = new StringBuffer()
      parse(buf)
      if (!tokens.isEmpty) {
        throw new Exception("nope")
      }
      println(buf)
    } catch {
      case e => println("Error occurred")
    }
  }
}