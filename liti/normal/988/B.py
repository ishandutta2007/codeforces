n = int(input())
s = []
for i in range(n):
    s.append(input())

s.sort(key=lambda x: len(x))

flag = True
for i in range(1, n):
    if s[i].count(s[i-1]) == 0:
        print("NO")
        flag = False
        break

if flag:
    print("YES")
    print('\n'.join(s))