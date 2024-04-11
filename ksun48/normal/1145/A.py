def t(a):
  if sorted(a) == a: yield len(a)
  else:
    yield from t(a[:len(a)//2])
    yield from t(a[len(a)//2:])

input()
a=list(map(int,input().split()))
print(max(t(a)))