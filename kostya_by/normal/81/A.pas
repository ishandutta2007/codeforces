program p1;
var
    ss : array[1..222222] of char;
    s : ansistring;
    i, j, h : longint;
begin
    readln(s);
    h:=0;
    for i:=1 to length(s) do begin
        if (h = 0) then begin
            inc(h);
            ss[h]:=s[i];
            continue;
        end;
        if (s[i] = ss[h]) then begin
            dec(h);
            continue;
        end;
        inc(h);
        ss[h]:=s[i];
    end;
    for i:=1 to h do write(ss[i]);
end.