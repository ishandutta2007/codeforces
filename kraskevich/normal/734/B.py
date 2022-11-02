xs = list(map(int, input().split()))
cnt_256 = min(xs[0], xs[2], xs[3])
cnt_32 = min(xs[0] - cnt_256, xs[1])
print(cnt_256 * 256 + cnt_32 * 32)