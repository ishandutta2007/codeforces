<?php
    $in = 'php://stdin';
//  $in = 'input.txt';

    $input = fopen($in, "r");

    list($n, $m) = explode(" ", trim(fgets($input)));
    
    $a = explode(" ", trim(fgets($input)));
    
    $i = 0;
    $j = $n-1;
    $l = 0;
        
    while ($i < $j) {
        
        $l = $l + $a[$j] - $a[$i];
        
        $i += $m;
        $j -= $m;
    }
    
    echo number_format(2 * $l, 0, "", "");
?>