n = int(input())
p = 0
for i in range(n):
    s = input()
    if s[1] == '+':
        p += 1
    else :
        p -= 1
print(p)