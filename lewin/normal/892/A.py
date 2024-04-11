n = int(raw_input())

a = sum(map(int, raw_input().split()))
b = sorted(map(int, raw_input().split()))

print (a <= b[-1] + b[-2]) * "YES" or "NO"