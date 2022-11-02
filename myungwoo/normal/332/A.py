N = input()
seq = raw_input()

n = N; ans = 0
while n < len(seq):
    if seq[n-1] == seq[n-2] == seq[n-3]:
        ans += 1
    n += N
print ans