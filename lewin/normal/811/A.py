a = map(int, raw_input().split())
who = 0
x = 1
while a[who] >= x:
    a[who] -= x
    x += 1
    who ^= 1
print (who == 0) * "Vladik" or "Valera"