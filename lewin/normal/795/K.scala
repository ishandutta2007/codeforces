object Main extends App {
    val n = readInt
    val s = readLine
    var pc = ' '
    var count = 0
    for (c <- s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            if (c == pc) {
                count += 1
            } else {
                if (count > 0) {
                    if (count == 2 && ((pc == 'o' || pc == 'e'))) {
                        print(pc)
                        print(pc)
                    } else {
                        print(pc)
                    }
                }
                pc = c
                count = 1
            }
        } else {
            if (count > 0) {
                if (count == 2 && ((pc == 'o' || pc == 'e'))) {
                    print(pc)
                    print(pc)
                } else {
                    print(pc)
                }
            }
            
            count = 0
            print(c)
        }
        pc = c
    }
    if (count > 0) {
        if (count == 2 && ((pc == 'o' || pc == 'e'))) {
            print(pc)
            print(pc)
        } else {
            print(pc)
        }
    }
    println()
}