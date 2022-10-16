n = int(raw_input())
arr = map(int, raw_input().split())
f = 0
b = n-1
while f < b:
    arr[f],arr[b] = arr[b],arr[f]
    f += 2
    b -= 2
print " ".join(map(str,arr))