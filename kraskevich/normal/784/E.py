xs = [int(input()) for _ in range(4)]
n = 0
for x in xs:
    n = n * 2 + x
d = {6: 0, 0: 0, 1: 1, 8: 1, 4: 0, 12: 1, 2: 0, 10 : 0, 14: 1, 9 : 1, 5: 0, 13: 0,
3: 1, 11: 1, 7: 0, 15: 1}
if n in d.keys():
    print(d[n])
else:
    xs = [0] * ((10 ** 6) * n)
    raise ValueError()