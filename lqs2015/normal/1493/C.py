test = int(input())
def check(k):
    for i in range(26):
        if num[i] % k != 0 :
            return 0
    return 1
def getval(k):
    res = 0
    for i in range(26):
        if num[i] % k != 0 :
            res += (k - num[i] % k)
    return res
for i in range(test):
    n, k = map(int, input().split(' '))
    s = input()
    if n % k != 0 :
        print(-1)
    else :
        num = [0,]
        num *= 26
        flg = 0
        for j in range(n):
            num [ord(s[j]) - ord('a')] += 1
        if check(k) == 1 :
            print(s)
            flg = 1
        else :
            for j in range(n - 1, -1, -1):
                num[ord(s[j]) - ord('a')] -= 1
                for h in range(ord(s[j]) - ord('a')+1, 26):
                    num[h] += 1
                    if getval(k) <= n - 1 - j :
                        flg = 1
                        res = s[0:j] + chr(ord('a') + h)
                        lst = n - 1 - j
                        for p in range(26):
                            if num[p] % k != 0 :
                                lst -= (k - num[p] % k)
                        res += 'a' * lst
                        for p in range(26):
                            if num[p] % k != 0 :
                                res += chr(ord('a') + p) * (k - num[p] % k)
                        print(res)
                        break
                    else :
                        num [h] -= 1
                if flg == 1 :
                    break
        if flg == 0 :
            print(-1)