uses
Math;

var
  w, h, u1, d1, u2, d2, h_: Int32;

begin
  ReadLn(w, h);
  ReadLn(u1, d1);
  ReadLn(u2, d2);
  for h_ := h downto 0 do
  begin
    w += h_;
    if h_ = d1 then
    begin
      w := max(0, w - u1);
    end;
    if h_ = d2 then
    begin
      w := max(0, w - u2);
    end;
  end;
  WriteLn(w);
  ReadLn;
end.