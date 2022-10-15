var
  x, counter, hh, mm: LongInt;

function Module(a, b: LongInt): LongInt;
begin
  If a >= 0 then Result := a mod abs(b)
            else Result := (abs(b) + (a mod abs(b))) mod abs(b);
end;

begin
  ReadLn(x);
  ReadLn(hh, mm);
  counter := 0;
  While (hh mod 10 <> 7) and (hh div 10 <> 7) and (mm mod 10 <> 7) and(mm div 10 <> 7) do
  begin
    inc(counter);
    If x > mm then
    begin
      mm := Module(mm-x, 60);
      hh := Module(hh-1, 24);
    end else mm := mm-x;
  end;
  WriteLn(counter);
  ReadLn;
end.