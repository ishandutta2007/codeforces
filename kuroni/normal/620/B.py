seg = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

def get_ans(u):
    ans = 0
    while u > 0:
        ans += seg[u % 10]
        u //= 10
    return ans

ans = 0
[a, b] = [int(i) for i in input().split(" ")]
for x in range(a, b + 1):
    ans += get_ans(x)
print(ans)