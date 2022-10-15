uses
  Math;

var
  n, pos, l, r, x: LongInt;
  left, right: Boolean;

begin
  read(n, pos, l, r);
  ReadLn;
  left:=True;
  right:=True;
  If l = 1 then left := False;
  If r = n then right:=False;
  If left then
  begin
    If right then
    begin
      x := min(abs(pos-l), abs(r-pos));
      x := x + r-l;
      inc(x, 2);
    end else
    begin
      x := abs(pos-l);
      inc(x);
    end;
  end else
  begin
    If right then
    begin
      x := abs(r-pos); 
      inc(x);
    end else
    begin
      x := 0;
    end;
  end;
  WriteLn(x);
end.