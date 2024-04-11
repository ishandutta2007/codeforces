def form(a):
    if not a:
        return "-"
    else:
        return "\"%s\"" % ",".join(a)


def main():
    a = []
    b = []
    s = raw_input()
    for ws in s.split(","):
        for w in ws.split(";"):
            if len(w) and w.isdigit() and (w[0] != "0" or len(w) == 1):
                a.append(w)
            else:
                b.append(w)

    print(form(a))
    print(form(b))

main()