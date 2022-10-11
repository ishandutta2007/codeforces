var ans, c0, c1, c2, c3: int64;
    i, o, n: longint;
begin
  read(n);
  c1 := 101;
  c2 := 101;
  c3 := 101;
  for i := 1 to n do
  begin
    read(o);
    if o = 3 then
    begin
      if (c1+1=i) then c2 := i;
      if (c2+1=i) then c1 := i;
      if (c0+1=i) or (c3+1=i) then c3 := i;
    end
    else
    begin
    if o = 0 then begin inc(ans); c0 := i end;
    if o = 1 then if (c1+1=i) then begin inc(ans); c0 := i; end else c1 := i;
    if o = 2 then if (c2+1=i) then begin inc(ans); c0 := i; end else c2 := i;
    end;
  end;
  write(ans);
end.