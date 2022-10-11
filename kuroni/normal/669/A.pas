var n,o:integer;
begin
    read(n);
    if n mod 3 = 0 then o := (n div 3) * 2
    else o:= (n div 3) * 2 + 1;
    write(o);
end.