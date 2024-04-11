n = map(int, raw_input())
s = raw_input()
ans = ""
for c in s:
  if not(c in "aeiouy" and ans and ans[-1] in "aeiouy"):
    ans += c
print ans