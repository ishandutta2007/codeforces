N = int(input())
S = input()

S = S.replace(')', '(')
A = S.split('(')

a = b = 0
for i, S in enumerate(A):
    words = S.split('_')
    for x in words:
        if len(x) == 0:
            continue
        if i % 2 == 0:
            a = max(a, len(x))
        else:
            b += 1
print(a, b)