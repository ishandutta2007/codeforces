from fractions import Fraction


def main():
    t1, t2, x1, x2, t0 = map(int, input().split())
    if t1 == t2:
        print(x1, x2)
    elif t1 == t0:
        print(x1, 0)
    elif t0 == t2:
        print(0, x2)
    else:
        res = Fraction(10 ** 18, 1)
        res_y1 = 0
        res_y2 = 0
        for y1 in range(x1 + 1):
            y2 = max(((t0 - t1) * y1 + t2 - t0 - 1) // (t2 - t0), 1 if y1 == 0 else 0)
            if y2 > x2:
                continue
            if y1 == 0:
                y2 = x2
            cur = Fraction(t1 * y1 + t2 * y2, y1 + y2)
            if cur <= res:
                res = cur
                res_y1 = y1
                res_y2 = y2
        print(res_y1, res_y2)


if __name__ == '__main__':
    main()