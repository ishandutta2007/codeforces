import sys

def query(l, r):
    print(f"? {l} {r}", flush=True)
    result = int(input())
    if result == -1:
        sys.exit(0)
    return result

def solve():
    n = int(input())

    total_inversions = query(1, n)
    l = 1
    r = n
    while l < r:
        c = (l + r) // 2
        if query(1, c) < total_inversions:
            l = c + 1
        else:
            r = c
    right_end = r
    min_len = max(int((total_inversions * 2)**0.5) - 10, 1)
    while min_len * (min_len - 1) // 2 < total_inversions:
        min_len += 1
    assert min_len < right_end
    assert min_len > 1
    min_len_inversions = query(right_end - min_len, right_end)
    right_len = min_len_inversions - query(right_end - min_len, right_end - 1) + 1
    l = 1
    r = n
    while l < r:
        c = (l + r) // 2
        if c * (c - 1) // 2 + right_len * (right_len - 1) // 2 < total_inversions:
            l = c + 1
        else:
            r = c
    left_len = r
    print(f"! {right_end - right_len - left_len + 1} {right_end - right_len + 1} {right_end}", flush=True)

d = int(input())
for _ in range(d):
    solve()