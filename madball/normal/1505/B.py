s = input()
while len(s) > 1:
    s = str(sum(map(int, s)))
print(s)