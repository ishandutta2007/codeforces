T = int(input())
while T > 0:
    T -= 1
    input()
    s = input()
    print(len(s) + len(set(s)))