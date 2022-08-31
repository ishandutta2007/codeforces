for i in range(10):
    print(i)
    x = input()
    if x == "great!" or x == "don't think so" or x == "not bad" or x == "cool" or x == "don't touch me":
        print("normal")
        break
    if x == "no way" or x == "don't even" or x == "are you serious?" or x == "worse" or x == "terrible":
        print("grumpy")
        break