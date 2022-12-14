k,n,w = map(int,input().split(' '))
print(max(int((w + 1) * w / 2 * k - n), 0))