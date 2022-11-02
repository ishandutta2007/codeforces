import sys

for i in range(10):
    print(i)
    sys.stdout.flush()
    s = input()
    if s in ["great!", "don't think so", "not bad", "cool" , "don't touch me"]:
        print("normal")
        exit(0)
    if s in ["no way", "don't even", "are you serious?", "worse", "terrible"]:
        print("grumpy")
        exit(0)