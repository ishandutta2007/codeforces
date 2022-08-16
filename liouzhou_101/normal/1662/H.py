from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    w, l = read_ints()
    tot = (w + l - 2) * 2
    ans = []
    i = 1
    while i * i <= tot and i <= min(w, l):
        if tot % i == 0:
            if w % i == 0 and (l - 2) % i == 0:
                ans.append(i)
            elif l % i == 0 and (w - 2) % i == 0:
                ans.append(i)
            elif l % i == 0 and (l - 2) % i == 0 and (w - 1) % i == 0:
                ans.append(i)
            elif w % i == 0 and (w - 2) % i == 0 and (l - 1) % i == 0:
                ans.append(i)
            elif (l - 1) % i == 0 and (w - 1) % i == 0:
                ans.append(i)

            if tot // i != i:
                rem = tot // i
                if w % rem == 0 and (l - 2) % rem == 0:
                    ans.append(rem)
                elif l % rem == 0 and (w - 2) % rem == 0:
                    ans.append(rem)
                elif l % rem == 0 and (l - 2) % rem == 0 and (w - 1) % rem == 0:
                    ans.append(rem)
                elif w % rem == 0 and (w - 2) % rem == 0 and (l - 1) % rem == 0:
                    ans.append(rem)
                elif (l - 1) % rem == 0 and (w - 1) % rem == 0:
                    ans.append(rem)
        i += 1
    print(len(ans), ' '.join(map(str, sorted(ans))))