n,k = map(int, raw_input().split())
w = map(int, raw_input().split())
w = map(lambda x: (x + k - 1) / k, w)
s = sum(w)
print (s+1)/2