n = int(input())
a = [0]*n

r = max(int(n-k-n/k+1) for k in range(1, n+1))
for i in range(1, n+1):
    if int(n-i-n/i+1) == r:
        k = i
        break

def query(b):
    for x in b:
        a[x] = 1
    print(k, end = " ")
    print(*[x+1 for x in b])
    x = int(input())-1
    for i in range(k):
        a[(x+i)%n] = 0

while True:
    b = []
    for i in range(n):
        if a[i] == 0 and i%k < k-1 and i != n-1:
            b.append(i)
    if len(b) < k: break
    query(b[:k])
    if sum(a) >= r: break

print(0)