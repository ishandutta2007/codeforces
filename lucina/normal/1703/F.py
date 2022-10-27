
for _ in range(int(input())):
    n = int(input())
    a = [0] + [int(x) for x in input().split()]
    bit = [0] * (n + 10)
    def update(idx, val):
        idx += 1
        while idx < len(bit):
            bit[idx] += val
            idx += idx & -idx
    def get(idx):
        res = 0
        idx += 1
        while idx > 0:
            res += bit[idx]
            idx -= idx & -idx
        return res
    ans = 0
    for i in range(1, n + 1):
        if (a[i] >= i): continue
        ans += get(max(-1, a[i] - 1))
        update(i, 1)
    print(ans)