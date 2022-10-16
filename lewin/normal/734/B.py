k2,k3,k5,k6 = map(int, raw_input().split())
nbig = min(k2,k5,k6)
k2 -= nbig
nsmall = min(k2,k3)
print nbig*256+nsmall*32