s = input()
cl = sum([1 for t in s if t.islower()])
cu = len(s) - cl
if cl < cu:
    s = s.upper()
else:
    s = s.lower()
print(s)