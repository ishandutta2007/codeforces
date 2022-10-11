var n, i, code, bf, af: longint;
    str,bfstr,afstr: string;
    ans: boolean;
begin
    ans := False;
    readln(n);
    for i := 1 to n do
    begin
        readln(str);
        delete(str,1,pos(' ',str));
        bfstr := copy(str,1,pos(' ',str)-1);
        delete(str,1,pos(' ',str));
        afstr := str;
        val(bfstr, bf, code);
        val(afstr, af, code);
        if (bf >= 2400) and (af > bf) then ans := True;
    end;
    if ans then write('YES') else write('NO');
end.