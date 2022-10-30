ans = 0; max = 0
N = input('')
A = map(int,raw_input('').split())
M = input('')
B = map(int,raw_input('').split())
for a in A:
    for b in B:
        if b%a == 0:
            c = b/a
            if max < c:
                max = c; ans = 1
            elif max == c:
                ans += 1
print ans