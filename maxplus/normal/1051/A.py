for _ in range(int(input())):
  s = input()
  lo = lambda s: sum(s.count(chr(c)) for c in range(ord('a'), ord('z') + 1))
  hi = lambda s: sum(s.count(chr(c)) for c in range(ord('A'), ord('Z') + 1))
  di = lambda s: sum(s.count(chr(c)) for c in range(ord('0'), ord('9') + 1))
  l = lo(s)
  h = hi(s)
  d = di(s)
  le = (not l) + (not h) + (not d)
  for i in range(0, len(s) - le):
    if l and l == lo(s[i:i+le]) or h and h == hi(s[i:i+le]) or d and d == di(s[i:i+le]):
      continue
    print(s[:i], 'a' * (not l), 'A' * (not h), '0' * (not d), s[i + le:], sep='')
    break