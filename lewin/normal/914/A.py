def issq(x):
    for i in range(-1000, 1000):
        if i*i == x:
            return False
    return True
n = int(raw_input())
arr = map(int, raw_input().split())
print max(filter(issq, arr))