def proc(n):
    global ans
    for c in str(n):
        if c in S:
            ans += 1
            return

N = input(); S = str(N); ans = 0
n = 1
while n*n <= N:
    if N%n == 0:
        proc(n)
        if N/n != n: proc(N/n)
    n += 1
print ans